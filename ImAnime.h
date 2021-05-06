#pragma once

/*
MIT License

Copyright (c) 2019-2020 fluid-love

https://github.com/fluid-love/ImAnime

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
/*
ImAnime Version:
	ver1.0.0 リリース 2021/05/07

*/


/*
ImGuiの既存の関数を利用しているだけで,ImGui内部の情報を直接いじることはない.

名前空間はImGuiとImAnime.
名前空間ImAnime::Internalは呼び出さないこと.
名前空間ImGuiは汎用的な目的.
ImAnimeで定義される関数は具体的に簡単に利用できるようにした.これらの関数は名前空間ImGuiの関数を利用して再現できる.

*/