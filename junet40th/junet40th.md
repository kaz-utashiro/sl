---
marp: true
theme: default
---

# sl

![](img/wikipedia.png)

--utashiro

---
# こんなのが走る
```
char *ban[] = {
    "      o \0\0\0\0",
    "     o \0\0\0\0\0",
    "    o  ____ ",
    "   --  |OO| ",
    "  _||__|  | ",
    " |        | ",
    "/-O=O O=O-- "
};
```

---
# sl
![h:350](img/sl-24.png) ![h:350](img/sl.gif)

---
# fj.sources or fj.jokes?
- 1985年
- fj.sources だっけ? fj.jokes かも?
- 環境
  - VAX-11/780 + 4.2BSD? (ASCII版?)
  - VT-100 or PC-9801
  - 9600bps RS232-C 接続

---
# 開発ソースを発見！
![](img/1985.png)

`sl.org.c` と `sl.c` という2つのファイルがある。

---
# 1985-08-10 は...
![h:600](img/1985-cal.png)

---
# sl.orig.c - curses library を使っている
```
    for (i=0; i <= width; i++) {
            for (j=0; j < 7; j++) {
                    move(j + ceil, 0);
                    delch();
                    move(j + ceil, NCOLS-2);
                    addch(*(ban[j]+i));
            }
            refresh();
    }
    for (i=NCOLS; i ; i--) {
            for (j=0; j < 7; j++) {
                    move(j + ceil, 0);
                    delch();
            }
            refresh();
    }
```

---
# sl.c - リリース版は fputs() に変更
```
    for (i=NCOLS; i ; i--) {
        for (j=0; j < 7; j++) {
            fputs (tgoto (CM, i, j + ceil), stdout);
            putns (ban[j], NCOLS - i);
        }
        refresh();
    }
    for (i=0; i <= width ; i++) {
        for (j=0; j < 7; j++) {
            fputs (tgoto (CM, 0, j + ceil), stdout);
            putns (ban[j] + i, 100);
        }
        refresh();
    }
```

---
# SIG_IGN 問題

- 開発ソースに `signal` の呼び出しは残っていない。
- fj に投稿する直前に入れたんじゃないだろうか
- でも `/* コメントアウト */` してた

---
# 進化を続ける sl

---
# 2010年版

---
# 2010年版
グラフィックを変更
```
char *sl[] = {
    "      o o o",
    "     o  ",
    "    o  ____  ",
    "   --  |OO|  ",
    "  _||__|  |  ",
    " |        |  ",
    "/-O=O O=O--  "
};
```

---
# 2010年版
![h:600](img/sl-2010.png)

---
# 2011年 jslinux 版

![h:600](img/sl-jslinux.png)

---
# 2023年版

---
# 2023年版
![h:600](img/sl-2023-1.png)

---
# 2023年版
罫線素片を使用してディテールを再現
```
char *sl[] = {
    "      o o o o",
    "     o       ",
    "    o  ┯━━┯  ",
    "   ╒╕  │OO│  ",
    " ┌─┘└──┘  │  ",
    "┌┘        │  ",
    "┴─O=O O=O─┴ з\n"
};
```

---
# one more thing

---
# ラッセル機能搭載
![h:600](img/sl-2023-2.png)

---
# sl-2023.c
```
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <term.h>
```

---
# sl-2023.c
走り終わった後も画面を消さないために結構苦労している。
```
void mvprintw(int y, int x, const char* fmt, const char* str) {
    tputs(tparm(tgoto(cursor_address, x, y)), 1, putchar);
    printf(fmt, str);
}
char *sl[] = {
    "      o o o o",
    "     o       ",
    "    o  ┯━━┯  ",
    "   ╒╕  │OO│  ",
    " ┌─┘└──┘  │  ",
    "┌┘        │  ",
    "┴─O=O O=O─┴ з\n"
};
int main() {
    setupterm(NULL, STDOUT_FILENO, NULL);
    int COLS = tigetnum("cols"), LINES = tigetnum("lines");
    int len = strlen(sl[0]), height = sizeof(sl)/sizeof(sl[0]);
    int start_x = COLS - len, start_y = LINES - height - 1;
    char dch2[20] = "", *dch2p = tparm(tigetstr("dch"), 2);
    if (dch2p != NULL)
        strcpy(dch2, dch2p);
    char smoke[1024]; strcpy(smoke, sl[0]); sl[0] = smoke;
    for (int x = start_x/2*2; x >= 0; x -= 2) {
        for (int y = 0; y < height; y++) {
            mvprintw(start_y + y, 0, "%s", dch2);
            mvprintw(start_y + y, x, "%s", sl[y]);
        }
        fflush(stdout);
        strcat(smoke, " o");
        usleep(100000);
    }
}
```

---
# Wikipedia
![h:600](img/wiki-history.png)

---
# 豊田版 sl

![h:500](img/toyoda-sl.png)

---
# mac 版
![h:500](img/macos.png)

---
# jslinux 版

![h:500](img/toyoda-sl-jslinux.png)

---
# javascript 版

![h:500](img/javascript.jpg)

---
# vimperator 版

![](img/vimperator.png)
https://atmarkit.itmedia.co.jp/news/200909/07/sl01.png

---
# https://github.com/kaz-utashiro/sl
- submodule 化したw
![](img/submodule.png)

---
# 1997年に書いた雑文より

    役に立たないものも作れないのに、役に立つものが作れるものか。

![](img/son.gif)