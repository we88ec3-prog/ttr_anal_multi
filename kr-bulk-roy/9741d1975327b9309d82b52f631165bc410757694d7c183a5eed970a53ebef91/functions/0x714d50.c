
int * FUN_00714d50(char *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905ace;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar4 = (int *)**(int **)(in_ECX + 0x104);
  if (piVar4 != *(int **)(in_ECX + 0x104)) {
    do {
      iVar2 = __stricmp((char *)(piVar4 + 2),param_1);
      if (iVar2 == 0) {
        if (piVar4 + 2 != (int *)0x0) {
          ExceptionList = local_10;
          return piVar4 + 2;
        }
        break;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(in_ECX + 0x104));
  }
  if ((DAT_00fe4b10 & 1) == 0) {
    DAT_00fe4b10 = DAT_00fe4b10 | 1;
    local_8 = 0;
    FUN_00714b50(uVar1);
    _atexit(FUN_00bd0790);
    local_8 = 0xffffffff;
  }
  iVar2 = *(int *)(in_ECX + 0x104);
  iVar3 = FUN_00714ef0(iVar2,*(undefined4 *)(iVar2 + 4),&DAT_00fe4a00);
  if (*(undefined **)(in_ECX + 0x108) != &DAT_00f0f0ef) {
    *(undefined **)(in_ECX + 0x108) = *(undefined **)(in_ECX + 0x108) + 1;
    *(int *)(iVar2 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    piVar4 = (int *)(*(int *)(*(int *)(in_ECX + 0x104) + 4) + 8);
    _strcpy_s((char *)piVar4,0x100,param_1);
    ExceptionList = local_10;
    return piVar4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

