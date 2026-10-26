
undefined4 FUN_006d6400(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *in_EAX;
  if (iVar3 != 0) {
    puVar2 = (undefined4 *)(iVar3 + 0xc);
    if (0xf < *(uint *)(iVar3 + 0x20)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    iVar3 = FUN_00495610(DAT_00fb1318,puVar2,0);
    if (iVar3 != 0) {
      (**(code **)(*(int *)*in_EAX + 0x30))(param_1,param_2);
      return 1;
    }
    FUN_006ded00(&DAT_00c40ac4);
    param_2 = 0x181;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_2);
    if (param_1 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    puVar2 = (undefined4 *)(param_1 + 0x10);
    if (7 < *(uint *)(param_1 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    FUN_00404b10(0xca,puVar2,&DAT_00bed1fc,0,0);
  }
  return 0;
}

