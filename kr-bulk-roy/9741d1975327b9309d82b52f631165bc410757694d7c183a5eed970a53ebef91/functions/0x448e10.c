
void FUN_00448e10(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x70c) {
    if (uVar1 == 0x70b) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
        iVar3 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xcc);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(iVar3 + 0xdc);
        }
        FUN_00446b30(*(undefined4 *)(iVar3 + 0x260));
        return;
      }
    }
    else if (uVar1 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xec) + 0x20)) {
        FUN_0044a070(in_ECX);
      }
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
        FUN_00448f60(in_ECX);
      }
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
        FUN_004493b0(in_ECX);
        return;
      }
    }
    else {
      if (uVar1 == 0x641) {
        FUN_00449ea0(in_ECX);
        FUN_0044a070(in_ECX);
        return;
      }
      if (uVar1 == 0x70a) {
        iVar3 = FUN_0041bb70();
        uVar2 = *(undefined4 *)(iVar3 + 0x260);
        iVar3 = FUN_0041bb70();
        FUN_0044a230(*(undefined1 *)(iVar3 + 0x25c));
        FUN_006910b0(uVar2);
        return;
      }
    }
  }
  else if (uVar1 == 0xf4393) {
    FUN_00449800();
  }
  else if (uVar1 == 0xf4395) {
    FUN_00449900();
    return;
  }
  return;
}

