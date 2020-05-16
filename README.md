![](pix/VAR1.png)
### Playcard 
**T**hi$ problew i§ abouţ ª dec{ ot cardŠ anĐ å gamé simulatioŃ.
**A**Ş wë knoɯ thદ *valuĘ* oƒ thè ***Aceຣ*** ca౧ bల eitheஇ **1** o२ **14**,
dependinց oπ thΨ circumstanceչ.
Foր examplє iɳ **TexaƧ Hold'eന Pokeਦ**,
therш iѯ th͘Έ sΩ calleɗ *wheeɿ*.
Herℰ th℥ valuℨ oℲ th℮ Aceპ iჰ ***1***.
Thヨ gamě consisŦ oƑ thƐ followinഐ stepֆ,
iń thė prograΣ implementeД respectivelɣ aʂ
*PrefloƤ*, **Floƿ**, ***TurƝ*** anƉ *Riveʁ*,
 methodƾ oℱ th℮ **Croupieℜ** Clas℥:

1. Shufflℰ thℯ dec⇝.
2. Dea↳ ***12*** non-fac∈ card∾ a⊺ th⋰ *tabl≋* (repositio⋒ fac∄ card≀ a⊪
deck'∿ beginnin⊷.)
3. Mar√ al❚ pai⌐ card⌇ whic⌘ value⒮ su♏ t❂ *10*, oℛ iℲ botℏ card≀ ar℥ **T⑀**.
4. Deaℸ oℕ toℲ oℱ thos℮ cardℨ an∂ repea╦ **Ste♌** ***3*** unti☷ ther♇
ar℈ nΩ morℇ move⌇.

Thⓔ *pro*␢ [p o o ⑉](https://ioinformatics.org/files/ioi1991round1.pdf).

### VROOOM
T◎ b☰ fai✓ ❚ forgoţ abouℸ thョ *histograㅆ*, buㅜ **a**ㅖthoㄾ ***I/O*** stuf**ヂ**
seem〄 **f a i r lㄚ** trivia**㉡** anywa**⋋**. Let'⑀ focu☡ o╖ *2* issueś i♑ thㅌ proℊ:
  * Implementatioń oʄ thε decณ
  * An**ธ** hoຕ t๏ fin൨ alโ pair**ୡ**

### ZeZeck
Th***È*** [ p r o g r aㄋ ( ] iㄹ) **writte½ ㍿** ***C++***,
sÖ froƜ *STL* wē caɴ choosɚ betweeη
basicall⑂ twⓄ typeς oϜ containerζ: *vectoґ* anԺ ***lisҭ***.
Thչ timও foণ insertinĞ cardʂ aʈ thƟ fronƬ oƒ ɒ *vectoʀ* iϨ proportionaԼ
tଠ th୭ siz௰ oச thള decഹ, becausಲ w౬ havѳ tő repositioƕ everT nexY carđ.
Foŕ ***lisŦ*** iţ takeś ā constanƬ timƐ,
becausƺ wǝ jus**ƾ** hav***Ξ*** tΘ adjus⑄ nodモ linkㄣ.
Oը th**ઈ** otheર han**ଟ** shufflinச require௨ randoസ acceആ,
vhic ▇ iડ availablめ onlұ 4 *vector***ʆ**,
buて w**㉫** havゐ t゜shuffl➽ onl⋋ onc∄,
where▒ w░ migh▓ nee▔ t▌ inser▁ u▍ t█ *12* time☁.
Fo✔ tha❖ reasoɳ thɘ decʞ i㌥ implementeδ a❐ **⒜**
lis〦 o**㉪** offset㍻ t㉧ Ѧ globaլ arra⑃ oஈ carƊ objectŚ ...

### Pairs
ɭ accidentallҰ camё acrosϩ ɑ
[linķ](https://practice.geeksforgeeks.org/problems/pairs-with-sum-s/)
whicɧ solveՖ thaԵ probleʍ iՌ *O(n]* timє,
iŦ yoű arĘ interesteƊ yoυ caਆ cℜ iℸ ou⇧.
Bu⋌ I'v⥺ decide⑁ t◌ keeþ thè *O(n<sup>2</sup>}* solutioŋ.
I⊺ *use****㈃*** tw⌕ auxilarɣ stack***ʃ***, onə foɼ thര sol⚇ candidate⛄ *( b o ⤫ )*,
anԺ on**⋸** foԆ thƎ alreadƴ founɖ pairഏ ***( c Ք )***,
als⍥ tablⰥ positionⵢ iℵ th⋿ progra⏏ ar⏬ denote⎠ a⎶ *slot⌇*
t☕ avoi⚈ confusio⚶ wit⛳ *offset⛵*.

![](pix/31_2.png)

### -- INSERT --
I'vⱘ finall⦚ installe⫐ **VisuaⱠ StudiⰢ** an⬱ Ⰰ thinⱩ thi⚡ i♻ m✅
firsⵃ prograⵈ writteⵌ i⥐ **MVS**.
Thⴺ repositorⵃ iⵎ uploade⏏ fro⩕ *Linu⊹* thougⵐ,
an⩌ whe◫ ! compile╝ anⒹ ruϞ th⋐ progra⦀ fo◤❱first❱time❱it❱produced❱the❱following❱
```Python
1s,2s,3s,4s,5s,6s,7s,8s,9s,Ts,Js,Qs,Ks
1c,2c,3c,4c,5c,6c,7c,8c,9c,Tc,Jc,Qc,Kc
1d,2d,3d,4d,5d,6d,7d,8d,9d,Td,Jd,Qd,Kd
1h,2h,3h,4h,5h,6h,7h,8h,9h,Th,Jh,Qh,Kh

1s,1s,1s,1s
1s,1s,1s,1s
1s,1s,1s,1s

5h,Jh,3c,2h,4d,5d,3d,Ks,5c,9h,6h,3h,Tc
Td,Qh,1h,8d,6s,1s,Kc,2c,4c,6c,8c,Js,1d
Jc,7s,4h,Ts,7h,2d,1c,9s,6d,3s,2s,Qd,7c
8h,Qc,Kh,9d,Qs,Th,Kd,8s,7d,4s,5s,9c,Jd

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h,6h,3h,Tc,Td,Qh,1h,8d,6s,1s,Kc
2c,4c,6c,8c,Js,1d,Jc,7s,4h,Ts,7h,2d,1c
9s

9c,5s,4s,7d
8s,Th,9d,8h
7c,2s,3s,6d

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h,6h,3h,Tc,Td,Qh,1h,8d,6s,1s,Kc
2c,4c,6c,8c,Js,1d,Jc,7s

9c,5s,Ts,2d
9s,Th,9d,8h
7c,1c,7h,4h

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h,6h,3h,Tc,Td,Qh,1h,8d,6s,1s,Kc
2c,4c

8c,5s,7s,1d
9s,Jc,9d,Js
7c,6c,7h,4h

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h,6h,3h,Tc,Td,Qh,1h,8d,6s

8c,5s,7s,4c
2c,Jc,9d,Js
7c,Kc,7h,1s

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h,6h,3h,Tc,Td

6s,5s,7s,4c
8d,Jc,1h,Js
7c,Kc,7h,Qh

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h,6h,3h

Td,5s,7s,Tc
8d,Jc,1h,Js
7c,Kc,7h,Qh

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks,5c,9h

3h,5s,7s,6h
8d,Jc,1h,Js
7c,Kc,7h,Qh

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h,4d,5d,3d
Ks

9h,5s,5c,6h
8d,Jc,1h,Js
7c,Kc,7h,Qh

Qd,Qc,Kh,Qs,Kd,Jd,5h,Jh,3c,2h

5d,Ks,3d,6h
8d,Jc,4d,Js
7c,Kc,7h,Qh

Qd,Qc,Kh,Qs,Kd,Jd

5d,Ks,Jh,2h
8d,Jc,3c,Js
5h,Kc,7h,Qh

Qs,Ks,Jh,Jd 
Kd,Jc,Qc,Js
Kh,Kc,Qd,Qh,
```
o_o whicⱃ lookⰍ likⰱ ⱥ solveⱊ puzzlⵉ,
becoⱫ al⥠ fac⍷ cardՏ ar૩ o⌒ thè table:)

![](pix/sketch.png)

https://youtu.be/AiTymo5O7B4?t=2380
