
undefined4 FUN_004eb650(int *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)((int)param_1 + 3) != '\0') {
    uVar4 = 0;
    uVar5 = *(int *)(in_ECX + 0x5eb0) - *(int *)(in_ECX + 0x5eac) >> 2;
    if (uVar5 != 0) {
      do {
        **(undefined4 **)(*(int *)(in_ECX + 0x5eac) + uVar4 * 4) = 0;
        iVar1 = uVar4 * 4;
        uVar4 = uVar4 + 1;
        *(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x5eac) + iVar1) + 0xe) = 10;
      } while (uVar4 < uVar5);
    }
  }
  if (param_2 < 4) {
    param_2 = 0;
  }
  else {
    param_2 = (param_2 - 4) / 0x14;
  }
  if (param_2 != 0) {
    piVar6 = (int *)((int)param_1 + 4);
    do {
      uVar4 = *(int *)(in_ECX + 0x5eb0) - *(int *)(in_ECX + 0x5eac) >> 2;
      uVar5 = 0;
      if (uVar4 != 0) {
        param_1 = *(int **)(in_ECX + 0x5eac);
        do {
          if (*(int *)(*param_1 + 4) == *piVar6) {
            puVar2 = *(uint **)(*(int *)(in_ECX + 0x5eac) + uVar5 * 4);
            if (puVar2 != (uint *)0x0) {
              *puVar2 = (uint)(*(char *)((int)piVar6 + 0xd) != '\n');
              *(char *)(puVar2 + 2) = (char)piVar6[2];
              *(undefined2 *)((int)puVar2 + 10) = *(undefined2 *)((int)piVar6 + 9);
              *(undefined2 *)(puVar2 + 3) = *(undefined2 *)((int)piVar6 + 0xb);
              *(undefined1 *)((int)puVar2 + 0xe) = *(undefined1 *)((int)piVar6 + 0xd);
              *(undefined2 *)(puVar2 + 4) = *(undefined2 *)((int)piVar6 + 0xe);
              *(char *)((int)puVar2 + 0x12) = (char)piVar6[4];
              *(undefined2 *)(puVar2 + 5) = *(undefined2 *)((int)piVar6 + 0x11);
              *(undefined1 *)((int)puVar2 + 0x16) = *(undefined1 *)((int)piVar6 + 0x13);
              puVar2[6] = piVar6[1];
            }
            break;
          }
          param_1 = param_1 + 1;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar4);
      }
      piVar6 = piVar6 + 5;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  FUN_008613c0(*(int *)(in_ECX + 0x5eac),*(int *)(in_ECX + 0x5eb0),
               *(int *)(in_ECX + 0x5eb0) - *(int *)(in_ECX + 0x5eac) >> 2,FUN_004e7f90,uVar3);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4259);
  ExceptionList = local_10;
  return 0;
}

