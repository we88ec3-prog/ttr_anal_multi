
void FUN_005e8d20(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009164bc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x3c) == 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    param_1 = 0x19d;
    FUN_005740f0(&param_1);
    if (in_ECX == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    piVar3 = (int *)(in_ECX + 0x10);
    piVar4 = piVar3;
    if (7 < *(uint *)(in_ECX + 0x24)) {
      piVar3 = (int *)*piVar3;
      piVar4 = piVar3;
    }
    do {
      iVar2 = *piVar3;
      piVar3 = (int *)((int)piVar3 + 2);
    } while ((short)iVar2 != 0);
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    param_1 = 0x19c;
    FUN_005740f0(&param_1);
    if (in_ECX == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    piVar3 = (int *)(in_ECX + 0x10);
    piVar4 = piVar3;
    if (7 < *(uint *)(in_ECX + 0x24)) {
      piVar3 = (int *)*piVar3;
      piVar4 = piVar3;
    }
    do {
      iVar2 = *piVar3;
      piVar3 = (int *)((int)piVar3 + 2);
    } while ((short)iVar2 != 0);
  }
  FUN_00404300(piVar4,(int)piVar3 - ((int)piVar4 + 2) >> 1);
  FUN_00404300(L"<br>",4);
  ExceptionList = local_10;
  return;
}

