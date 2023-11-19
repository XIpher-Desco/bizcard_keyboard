# XiBiz mini keypad
![bizcard_picture](/image/xibiz_pict.jpg)

名刺サイズの小さな左手用キーパッド

# キーマッピングの方法
## 設定ファイルのダウンロード

https://github.com/XIpher-Desco/bizcard_keyboard/releases

のページを開き、Assetsから xibiz.json をダウンロードします。

## キーマッピングの設定
https://usevia.app/design

このページを開き、 Load Draft Definition の Load をクリックします。

ファイル選択画面になるので、先程ダウンロードした xibiz.json を選択します。

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

[参考動画](https://www.youtube.com/watch?v=Ap_3zZtk4TI&loop=0)

# ビルド

## ビルド手順
1から構築する手順です

### パーツ
[Parts list picture](/image/parts.JPG)
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

![insert pin]()

基板の印字とマイコンの印字が合うように置きます。

![マイコン on pin]()

端の４箇所をハンダ付けして、ピンが傾いていないかなどの調整をします。傾きや差し込みの不良がなければ、全ての箇所にハンダ付けをします。

### 4. マイコンへの書き込み及びテスト

#### 4.1 ファームウェアの書き込み
QMK MSYS を使用して、書き込みます。

keyboards\xipher\xibiz を QMK Firmware の keyboards に追加します

以下のコマンドで、via対応版を書き込みます
```qmk flash -kb xipher/xibiz -km via```

#### 4.2 テスト

keytester で入力をチェックします

https://usevia.app/test

### 5. キースイッチをハンダ付け

### 6. ロータリーエンコーダのハンダ付け

### 7. マッピング
[キーマッピングの方法](#キーマッピングの方法)