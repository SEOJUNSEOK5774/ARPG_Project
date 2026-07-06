# Third-Person Action RPG Combat System

Unreal Engine 5 と C++ を使用して制作した、三人称アクションRPG向けの戦闘システムです。  
Gameplay Ability System（GAS）を使用し、攻撃、武器Collision、ダメージ計算、ガード判定、ターゲットロック、UI更新などを実装しました。

学生ポートフォリオ作品として、ゲーム全体の完成度よりも、戦闘処理をどのように分けて実装するかを重視して制作しています。

---

## 使用技術

- Unreal Engine 5
- C++
- Gameplay Ability System
- GameplayTag
- GameplayEvent
- Enhanced Input
- UMG

---

## 主な実装内容

- CombatComponent による武器管理と戦闘処理の分離
- Weapon Collision の有効化 / 無効化制御
- Overlap による攻撃命中判定
- GameplayEvent を使用した GAS 連携
- GameplayEffect によるダメージ処理
- AttributeSet による HP / Rage 管理
- GameplayTag による入力、状態、イベント管理
- プレイヤー攻撃 / 敵攻撃
- ガード / ブロック判定
- HitPause による打撃感の演出
- ターゲットロック機能
- UIコンポーネントを通したステータス更新

---

## 戦闘システムの流れ

```text
Input
→ GameplayAbility 発動
→ 攻撃アニメーション再生
→ Weapon Collision 有効化
→ Overlap 判定
→ GameplayEvent 送信
→ GameplayEffect 適用
→ AttributeSet 更新
→ UI 反映

設計方針
戦闘処理を一つのクラスにまとめず、役割ごとに分けることを意識しました。
CombatComponent
武器の登録、現在装備中の武器管理、Collision切り替えを担当

WeaponBase
武器CollisionとOverlap検出を担当

GameplayAbility
攻撃、ガード、ターゲットロックなどのアクション処理を担当

GameplayEffect
ダメージやステータス変化を担当

AttributeSet
HP、Rageなどのステータス管理を担当

UIComponent
Attribute変更時のUI更新通知を担当

主要コード
ファイル	役割
PawnCombatComponent.cpp	武器登録、装備武器管理、Collision制御
WarriorWeaponBase.cpp	武器CollisionのOverlap検出
WarriorAbilitySystemComponent.cpp	Ability入力処理、Ability管理
WarriorHeroGameplayAbility.cpp	プレイヤー側Abilityの共通処理
WarriorEnemyGameplayAbility.cpp	敵側Abilityの共通処理
GEExcCalc_DamageTaken.cpp	ダメージ計算
WarriorAttributeSet.cpp	HP / Rage 更新、死亡判定、UI通知
HeroGameplayAbility_TargetLock.cpp	ターゲットロック処理

こだわった点
GameplayTag を使った管理
入力、武器、状態、イベントを GameplayTag で管理することで、文字列や個別フラグに依存しすぎない構成にしました。
GameplayEvent による GAS 連携
武器Collisionで命中を検出した後、GameplayEvent を通して Ability 側に処理を渡すことで、武器判定とダメージ処理を分離しています。
CombatComponent の分離
キャラクター本体に戦闘処理を直接持たせず、CombatComponent に武器管理やCollision制御をまとめることで、プレイヤーと敵の両方で使いやすい構成を目指しました。
ターゲットロック
周囲の敵を検索し、対象を固定するターゲットロック機能を GameplayAbility として実装しました。
カメラ制御、対象切り替え、状態タグによる制限なども含めています。
今後の改善点
デバッグ表示やログの整理
命名ミスの修正
ダメージ計算の例外処理強化
敵AIや攻撃パターンの拡張
UI演出やフィードバックの改善
コードコメントの整理
