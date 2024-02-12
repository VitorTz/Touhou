#pragma once


namespace th {


    enum GameObjState {

        Idle = 1 << 0,
        Moving = 1 << 1,
        Attack = 1 << 2,
        Damage = 1 << 3,
        
        Left = 1 << 4,
        Right = 1 << 5,
        Down = 1 << 6,
        Up = 1 << 7,
        
        LeftIdle = Left | Idle,
        RightIdle = Right | Idle,
        UpIdle = Up | Idle,
        DownIdle = Down | Idle,

        LeftMoving = Left | Moving,
        RightMoving = Right | Moving,
        UpMoving = Up | Moving,
        DownMoving = Down | Moving,

        LeftAttack = Left | Attack,
        RightAttack = Right | Attack,
        UpAttack = Up | Attack,
        DownAttack = Down | Attack,

        LeftDamage = Left | Damage,
        RightDamage = Right | Damage,
        UpDamage = Up | Damage,
        DownDamage = Down | Damage

    };
    
} // namespace th
