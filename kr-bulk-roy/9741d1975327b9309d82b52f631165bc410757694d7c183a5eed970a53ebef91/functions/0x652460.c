
undefined4 FUN_00652460(uint param_1)

{
  undefined4 *puVar1;
  
  if (param_1 < 0x2afb) {
    if (param_1 == 0x2afa) {
      puVar1 = (undefined4 *)FUN_00891268(0x14);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = FoxUI::FXUIEvent::vftable;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf43e5;
        FUN_004072a0();
        return 1;
      }
      FUN_004072a0();
    }
    else {
      switch(param_1) {
      case 0x11:
        FUN_00404ba0();
        FUN_0050c640(1);
        return 1;
      case 0x12:
        FUN_00404ba0();
        FUN_0050c640(2);
        return 1;
      case 0x13:
        FUN_00404ba0();
        FUN_0050c640(3);
        return 1;
      case 0x14:
        FUN_00404ba0();
        FUN_0050c640(4);
        return 1;
      }
    }
  }
  return 1;
}

