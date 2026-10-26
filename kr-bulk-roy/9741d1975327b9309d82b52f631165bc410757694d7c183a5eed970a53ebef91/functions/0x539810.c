
undefined4 FUN_00539810(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int in_EDX;
  int *piVar4;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  uVar2 = *(int *)(in_EDX + 0x2c) - *(int *)(in_EDX + 0x28) >> 2;
  uVar3 = 0;
  if (uVar2 != 0) {
    piVar4 = *(int **)(in_EDX + 0x28);
    do {
      if ((*(char *)(*piVar4 + 10) != '\0') && (*(int *)*piVar4 == unaff_EDI)) {
        puVar1 = (undefined4 *)(*(int **)(in_EDX + 0x28))[uVar3];
        *puVar1 = 0;
        puVar1[1] = 0;
        *(undefined1 *)(puVar1 + 2) = 0;
        *(undefined2 *)((int)puVar1 + 10) = 0;
        return 1;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf4404);
  ExceptionList = local_10;
  return 0;
}

