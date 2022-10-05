@echo off
setlocal enableDelayedExpansion
set "spcs= "
for /l %%n in (1 1 12) do set "spcs=!spcs!!spcs!"
findstr /n "^" "%~1" >"%~1.tmp"
setlocal disableDelayedExpansion
(
  for /f "usebackq delims=" %%L in ("%~1.tmp") do (
    set "ln=%%L"
    setlocal enableDelayedExpansion
    set "ln=!ln:*:=!"
    set /a "n=4096"
    for /l %%i in (1 1 13) do (
      if defined ln for %%n in (!n!) do (
        if "!ln:~-%%n!"=="!spcs:~-%%n!" set "ln=!ln:~0,-%%n!"
        set /a "n/=2"
      )
    )
    echo(!ln!
    endlocal
  )
) >"%~1"
del "%~1.tmp" 2>nul
