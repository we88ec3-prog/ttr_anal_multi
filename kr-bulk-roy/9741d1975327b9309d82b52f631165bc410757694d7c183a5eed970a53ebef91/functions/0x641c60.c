
void FUN_00641c60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x130) + 0x24c);
  if (iVar1 == 0) goto switchD_00641ca4_default;
  iVar1 = *(int *)(iVar1 + 0xcc);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xdc);
  }
  if (iVar1 == 0) goto switchD_00641ca4_default;
  switch(*(undefined4 *)(iVar1 + 0x20)) {
  case 0:
    uVar2 = FUN_00761520();
    uVar4 = 3;
    break;
  case 1:
    uVar2 = FUN_00761520();
    uVar4 = 2;
    break;
  case 2:
    iVar1 = *(int *)(*(int *)(param_1 + 0x134) + 0x24c);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0xcc);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0xdc);
      }
      if (iVar1 != 0) {
        uVar2 = FUN_00761520();
        uVar3 = 1;
        uVar4 = FUN_0040f8c0(1,uVar2);
        FUN_004d5ae0(uVar4,uVar3,uVar2);
        FUN_00641d90(param_1);
        return;
      }
    }
    goto switchD_00641ca4_default;
  case 3:
    uVar2 = FUN_00761520();
    uVar4 = 0;
    break;
  case 4:
    uVar2 = FUN_00761520();
    uVar4 = 6;
    break;
  default:
    goto switchD_00641ca4_default;
  }
  uVar3 = FUN_0040f8c0(uVar4,uVar2);
  FUN_004d5ae0(uVar3,uVar4,uVar2);
switchD_00641ca4_default:
  FUN_00641d90(param_1);
  return;
}

