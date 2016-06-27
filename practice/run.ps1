param
(
    [Parameter(Mandatory)]
    [string]
    $problemName,

    $isOneLinePerCase = $true
)

if(Test-Path $problemName)
{
    $fileInfo = (ls $problemName);
    $problemName = $fileInfo.Name.Replace($fileInfo.Extension, [string]::Empty);
}

if(-not (Test-Path (".\{0}.cpp" -f $problemName))){
    throw "$problemName.cpp doesn't exist";
}

Write-Host "Compling...";
[string]$command = ("g++ -std=c++0x {0}.cpp" -f $problemName);
Invoke-Expression $command;

if($LASTEXITCODE -ne 0)
{
    Write-Host "Compile failed. Exit.";
    return;
}
Write-Host "Start executing...";
ls (".\data\{0}" -f $problemName) | ?{$_.PSIsContainer -eq $false} | %{
    Write-Host "Executing for $_";
    if($isOneLinePerCase)
    {
        gc $_.fullname | %{Write-Host $_; $_ | .\a.exe};
    }
    else
    {
        (gc $_.fullname | %{write-host $_});
        gc $_.fullname | .\a.exe;
    }
}