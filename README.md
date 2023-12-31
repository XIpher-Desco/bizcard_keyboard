# XiBiz mini keypad
![bizcard_picture](/image/xibiz_pict.jpg)

名刺サイズの小さな左手用キーパッド

# キーマッピングの方法

VIA を使ったマッピングについては「[（初心者編）VIAを使ってキーマップを書き換えよう](https://salicylic-acid3.hatenablog.com/entry/via-manual)」のページが非常に詳しくされていますので、参考にしてください。

## 設定ファイルのダウンロード

https://github.com/XIpher-Desco/bizcard_keyboard/releases

のページを開き、Assetsから xibiz.json をダウンロードします。

12月以降入手した方は、ファームウェアが更新されているため、v1.1 の xibiz_rev2.json

## キーマッピングの設定
https://usevia.app/design

このページを開き、 Load Draft Definition の Load をクリックします。

ファイル選択画面になるので、先程ダウンロードした `xibiz.json/xibiz_rev2.json` を選択します。

画面にチョコレートのような画像が表示されたら、設定完了です。

## キーマッピング
https://usevia.app/

このページを開き、キーボードを USB ケーブルで PC とつなぎます。

左上に 「usevia.app が HID デバイスへの接続を要求しています」と表示されるので、 xibiz_pad を選択し、接続をクリックします。

![Via keypad select picture](/image/via_select.png)

画面が消えてしまった場合は、画面中央の Authorize device ＋ を選択してください。

### キーの変更
変更したいキーを選び、下の列から選択します。通常の A~Z のキーの他、数字や音量キーなども設定出来ます。

右４つキーはノブの回転です、１回転するたびに、１回入力されます

rev2 ではノブをクリックして変更するシステムになっています。キーコードを直接入力する必要があります

入力方法は、Anyキーと同じなので、こちらの[Anyキーを投入する](https://salicylic-acid3.hatenablog.com/entry/via-manual#:~:text=%E3%81%8C%E3%81%82%E3%82%8A%E3%81%BE%E3%81%99%E3%80%82-,Any%E3%82%AD%E3%83%BC%E3%82%92%E6%8A%95%E5%85%A5%E3%81%99%E3%82%8B,-%E5%AE%9F%E3%81%AFQMK%E3%81%A8%E3%81%84%E3%81%86)を参考にしてください。キーコードは[キーコード一覧](https://docs.qmk.fm/#/keycodes)から確認出来ます


[参考動画](https://www.youtube.com/watch?v=Ap_3zZtk4TI&loop=0)


## デフォルトキーマッピング
12月以降では、デフォルトキーマッピングが設定されています。
こちらはクリスタ基準のショートカットです。

![クリスタのショートカットマッピング](image/keymap_rev2.png)

# ビルド

## ビルド手順
1から構築する手順です

### パーツ
![Parts list picture](/image/parts.JPG)

- [promicro](https://talpkeyboard.net/items/61f4604eacbcb036350954b6) x1
- ダイオード 以下２種類のうちどちらか x9
  - [スルーホール](https://talpkeyboard.net/items/59eadbffc8f22c15de001638)
  - [SMD](https://talpkeyboard.net/items/6294480b0ebded1af895c437)
- [ロータリエンコーダ](https://talpkeyboard.net/items/5f3f1a597df28129f2fd4b0f) x2
- [お好みのキースイッチ](https://shop.yushakobo.jp/products/6140) x7 リンクは個人的おすすめ

### オプション
光らせる場合
- [SK6812MINI-E](https://akizukidenshi.com/catalog/g/gI-15478/)

-E の付かないものは別物なので、型番に注意してください

### 1. ダイオードのハンダ付け

向きに気をつけてハンダ付けします。
こちらの方のページが非常に参考になります。

https://docs.dailycraft.jp/buildguides/sandboxv2/diode_th.html

https://docs.dailycraft.jp/buildguides/sandboxv2/diode_smd.html

### 2. LED のハンダ付け(オプション)
熱に非常に弱いため、一気に４箇所をハンダ付けすると、本体に熱が籠もり破損する可能性が高くなります。１箇所ハンダ付けしたら、別のLEDのハンダ付けというように、時間を置いて４箇所ハンダ付けするようにします。

短時間の加熱で済むようにするため、フラックスを塗布することを推奨します。

LEDの向きに気をつけてハンダ付けします。

光る面が表（さいふちゃんが描かれている方）になるようにします。４つの足のうち、１つだけ斜めに切り欠きが設けてあります。切り欠きをL字になっている角に合わてハンダ付けします。

![LED soldering](/image/SK6812MINI-E.JPG)

### 3. マイコンのハンダ付け
基板側はハンダ付けしなくとも良い仕様になっています。接触不良が考えられる場合は、基板側もハンダ付けしてください。

マイコンに付属しているピンを基板に差し込みます。少し固めですがまっすぐ最後まで差し込みます。

![insert pin](/image/Pin1.JPG)

基板の印字とマイコンの印字が合うように置きます。

![マイコン on pin](/image/Pin2.JPG)

端の４箇所をハンダ付けして、ピンが傾いていないかなどの調整をします。傾きや差し込みの不良がなければ、全ての箇所にハンダ付けをします。

### 4. マイコンへの書き込み及びテスト

#### 4.1 ファームウェアの書き込み
[QMK MSYS](https://msys.qmk.fm/) を使用して、書き込みます。

ホームページから、インストーラーを使用してインストールをしておきます。

keyboards\xipher\xibiz を QMK Firmware の keyboards にコピーします

以下のコマンドで、via対応版の書込みを実行します。
```qmk flash -kb xipher/xibiz -km via```

基板上の RESET をショートさせると、書込みが始まります。 2回素早くショートさせる必要があるマイコンもあるので、書込みが始まらない場合は、試してみてください。

このタイミングで LED が光るので直視しないように気をつけてください。（

#### 4.2 テスト

キースイッチを差し込む前に keytester で入力をチェックします

https://usevia.app/test

キースイッチの足が入る２箇所をショートさせることで、ダイオードが正しくついているか、基板とマイコンが正しく接続されているか確認できます。

### 5. キースイッチをハンダ付け

表面からキースイッチを差し込み、ハンダ付けをします。

3pin式のキースイッチは、斜めになりやすいです。

２箇所を一気にハンダ付けせず、片足だけハンダ付けして並べてから調整すると整列させやすいです。

### 6. ロータリーエンコーダのハンダ付け

ロータリーエンコーダを差し込みハンダ付けします。可能な限り最後に取り付けます。

5pin + 2箇所の補助があるので、引っ掛かりがないように差し込みます。

２箇所の補助にはハンダ付けは不要です。

### 7. マッピング
ページ上部の[キーマッピングの方法](#キーマッピングの方法)を参考にマッピングが出来ます