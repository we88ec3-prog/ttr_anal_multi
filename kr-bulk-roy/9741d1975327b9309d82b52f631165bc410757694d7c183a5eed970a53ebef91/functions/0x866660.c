
void FUN_00866660(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + 4;
  if (*(int *)(param_1 + 0x58) != 0) {
    cVar2 = FUN_00783ac0();
    if (cVar2 == '\0') {
      iVar4 = 0;
    }
    iVar3 = _fclose(*(FILE **)(param_1 + 0x58));
    if (iVar3 == 0) goto LAB_00866691;
  }
  iVar4 = 0;
LAB_00866691:
  *(undefined1 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  FUN_00730d00();
  uVar1 = DAT_00fe31e4;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (iVar4 == 0) {
    FUN_00431a90(0);
  }
  return;
}

