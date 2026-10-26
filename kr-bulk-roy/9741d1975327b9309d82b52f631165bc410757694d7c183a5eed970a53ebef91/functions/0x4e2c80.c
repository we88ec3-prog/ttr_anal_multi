
undefined4 FUN_004e2c80(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(int *)(param_1 + 2) == 0) {
    if (*(char *)(param_1 + 8) == '\x01') {
      param_1 = 0x160;
      iVar2 = FUN_005854b0();
      FUN_005740f0(&param_1);
      if (in_ECX != *(int *)(iVar2 + 4)) {
        puVar3 = (undefined4 *)(in_ECX + 0x10);
        if (7 < *(uint *)(in_ECX + 0x24)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        FUN_00404b10(0xca,puVar3,&DAT_00bed1fc,0,0);
        return 0;
      }
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    if (*(char *)(param_1 + 8) != '\x02') {
      uVar4 = 0x15f;
      FUN_005854b0(0x15f,&DAT_00bed1fc,0,0);
      uVar4 = FUN_00585330(uVar4);
      FUN_00404b10(0xca,uVar4);
      FUN_004054c0();
      FUN_0058aad0(0xf4432);
      return 0;
    }
  }
  else {
    if (*(int *)(param_1 + 2) != 1) {
      return 0;
    }
    if (*(char *)(param_1 + 8) == '\x01') {
      param_1 = 0x162;
      iVar2 = FUN_005854b0();
      FUN_005740f0(&param_1);
      if (in_ECX != *(int *)(iVar2 + 4)) {
        puVar3 = (undefined4 *)(in_ECX + 0x10);
        if (7 < *(uint *)(in_ECX + 0x24)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        FUN_00404b10(0xca,puVar3,&DAT_00bed1fc,0,0);
        return 0;
      }
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    if (*(char *)(param_1 + 8) != '\x02') {
      iVar2 = FUN_00404ba0();
      FUN_004d4540(*(undefined4 *)(iVar2 + 0x6924),0);
      uVar4 = 0x161;
      FUN_005854b0(0x161,&DAT_00bed1fc,0,0);
      uVar4 = FUN_00585330(uVar4);
      FUN_00404b10(0xca,uVar4);
      FUN_004054c0();
      puVar3 = (undefined4 *)FUN_00891268(0x14);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf4410;
        FUN_0058aa50(puVar3);
        return 0;
      }
      FUN_0058aa50(0);
      return 0;
    }
  }
  uVar4 = 0xe8;
  FUN_005854b0(0xe8,&DAT_00bed1fc,0,0);
  uVar4 = FUN_00585330(uVar4);
  FUN_00404b10(0xca,uVar4);
  return 0;
}

