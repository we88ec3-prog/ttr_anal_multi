
void FUN_0060bb60(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  undefined4 uVar5;
  
  FUN_00744ca0(param_1);
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 0xcb) {
    uVar2 = (uint)*(ushort *)(in_ECX + 0x95);
    uVar4 = (uint)*(byte *)(in_ECX + 0x93);
    iVar3 = in_ECX[0x92];
    FUN_0046fee0(iVar3,uVar4,uVar2);
    iVar3 = FUN_0060c660(iVar3,uVar4,uVar2);
    in_ECX[0x96] = iVar3;
    (**(code **)(*in_ECX + 0x50))(iVar3);
    return;
  }
  if (iVar3 != 0xcc) {
    if ((iVar3 == 200) && (in_ECX[0x96] != 0)) {
      uVar5 = 0x1d;
      FUN_00443dc0(0x1d);
      iVar3 = FUN_006f1b90(uVar5);
      if (iVar3 != 1) {
        uVar5 = 0x9d;
        FUN_00443dc0(0x9d);
        iVar3 = FUN_006f1b90(uVar5);
        if (iVar3 != 1) {
          return;
        }
      }
      *(bool *)(in_ECX[0x96] + 0x1ec) = *(char *)(in_ECX[0x96] + 0x1ec) == '\0';
      if (*(char *)(in_ECX[0x96] + 0x1ed) != '\0') {
        uVar2 = (uint)*(ushort *)(in_ECX + 0x95);
        uVar4 = (uint)*(byte *)(in_ECX + 0x93);
        iVar3 = in_ECX[0x92];
        FUN_0046fee0(iVar3,uVar4,uVar2);
        iVar3 = FUN_0060c660(iVar3,uVar4,uVar2);
        in_ECX[0x96] = iVar3;
        FUN_00749a00(0,0);
        uVar5 = FUN_00404aa0();
        FUN_0074f980(uVar5);
      }
    }
    return;
  }
  pcVar1 = *(code **)(*in_ECX + 0x54);
  in_ECX[0x96] = 0;
  (*pcVar1)();
  return;
}

