
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004700a0(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  FUN_00744ca0(param_1);
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 == 0xcb) {
    if ((_DAT_00fc0db0 & 1) == 0) {
      _DAT_00fc0db0 = _DAT_00fc0db0 | 1;
      DAT_00fc0db4 = 0;
      DAT_00fc0db8 = 0;
      DAT_00fc0dbc = 0;
      DAT_00fc0dc0 = 0;
      _atexit((_func_4879 *)&DAT_00bcd9e0);
    }
    iVar2 = FUN_0060c660((short)in_ECX[0x93],*(undefined1 *)((int)in_ECX + 0x24e),
                         *(undefined1 *)((int)in_ECX + 0x24f));
    in_ECX[0x94] = iVar2;
    (**(code **)(*in_ECX + 0x50))(iVar2);
    return;
  }
  if (iVar2 != 0xcc) {
    if ((iVar2 == 200) && (in_ECX[0x94] != 0)) {
      uVar6 = 0x1d;
      FUN_00443dc0(0x1d);
      iVar2 = FUN_006f1b90(uVar6);
      if (iVar2 != 1) {
        uVar6 = 0x9d;
        FUN_00443dc0(0x9d);
        iVar2 = FUN_006f1b90(uVar6);
        if (iVar2 != 1) {
          return;
        }
      }
      *(bool *)(in_ECX[0x94] + 0x1ec) = *(char *)(in_ECX[0x94] + 0x1ec) == '\0';
      if (*(char *)(in_ECX[0x94] + 0x1ed) != '\0') {
        uVar4 = (uint)*(byte *)((int)in_ECX + 0x24f);
        uVar5 = (uint)*(byte *)((int)in_ECX + 0x24e);
        uVar3 = (uint)*(ushort *)(in_ECX + 0x93);
        FUN_0046fee0(uVar3,uVar5,uVar4);
        iVar2 = FUN_0060c660(uVar3,uVar5,uVar4);
        in_ECX[0x94] = iVar2;
        FUN_00749a00(0,0);
        uVar6 = FUN_00404aa0();
        FUN_0074f980(uVar6);
      }
    }
    return;
  }
  pcVar1 = *(code **)(*in_ECX + 0x54);
  in_ECX[0x94] = 0;
  (*pcVar1)();
  return;
}

