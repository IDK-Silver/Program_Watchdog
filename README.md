# 程式監控

# 編譯說明

## 環境

- Python 3
- Visual Studio 2019 C++
- Windows 10

## CMake 設定

- BUILD_PID_TEST_PROGRAM
  - 是否要編譯測試程式

## 測試說明

編譯完成後會有兩了執行檔案

1. program_watchdog.exe
2. pid_test.exe

把這兩個執行檔案放到專案目錄下的test資料夾內

執行 test_script.py
```
python.exe test_script.py
```


# 使用說明

- 使用格式
  - -m 後面要監控的主程式PID (只能輸入一個)
  - -w  要關閉的程式 (可以接受多個數入, 每個輸入以空白分開)

```
.\program_watchdog -m main_program_pid -w close_pid_1 colse_pid_2
```

- 使用範例
  - 假設要監控的主程式PID : 1
  - 要關閉的程式PID為 : 10 11 12
```
.\program_watchdog -m 1 -w 10 11 12
```





