
void FUN_004327c0(void)

{
  uint uVar1;
  int iVar2;
  uint *in_ECX;
  undefined4 *puVar3;
  _Lockit local_8 [4];
  
  uVar1 = *in_ECX;
  if (uVar1 != 0) {
    std::_Lockit::_Lockit(local_8,0);
    iVar2 = *(int *)(uVar1 + 4);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      *(int *)(uVar1 + 4) = iVar2 + -1;
    }
    iVar2 = *(int *)(uVar1 + 4);
    FUN_0087dd6f();
    puVar3 = (undefined4 *)(~-(uint)(iVar2 != 0) & uVar1);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
  }
  return;
}

