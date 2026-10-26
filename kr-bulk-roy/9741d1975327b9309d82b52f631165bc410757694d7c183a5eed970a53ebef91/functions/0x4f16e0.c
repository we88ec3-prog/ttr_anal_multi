
undefined4 FUN_004f16e0(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int in_ECX;
  uint *puVar5;
  uint uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009248cc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(byte *)((int)param_1 + 2) & 1) != 0) {
    uVar3 = 0;
    uVar6 = *(int *)(in_ECX + 0x5eb0) - *(int *)(in_ECX + 0x5eac) >> 2;
    if (uVar6 != 0) {
      do {
        **(undefined4 **)(*(int *)(in_ECX + 0x5eac) + uVar3 * 4) = 0;
        iVar1 = uVar3 * 4;
        uVar3 = uVar3 + 1;
        *(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x5eac) + iVar1) + 0x12) = 10;
      } while (uVar3 < uVar6);
    }
  }
  if ((*(byte *)((int)param_1 + 2) & 2) != 0) {
    uVar3 = 0;
    uVar6 = *(int *)(in_ECX + 0x5ed4) - *(int *)(in_ECX + 0x5ed0) >> 2;
    if (uVar6 != 0) {
      do {
        **(undefined4 **)(*(int *)(in_ECX + 0x5ed0) + uVar3 * 4) = 0;
        iVar1 = uVar3 * 4;
        uVar3 = uVar3 + 1;
        *(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x5ed0) + iVar1) + 0x12) = 10;
      } while (uVar3 < uVar6);
    }
    if (*(int *)(in_ECX + 0x5ecc) != 0) {
      **(undefined4 **)(in_ECX + 0x5ecc) = 0;
      *(undefined1 *)(*(int *)(in_ECX + 0x5ecc) + 0x12) = 10;
    }
  }
  if (param_2 < 6) {
    param_2 = 0;
  }
  else {
    param_2 = (param_2 - 6) / 0xd;
  }
  if (param_2 != 0) {
    puVar5 = (uint *)((int)param_1 + 6);
    do {
      param_1 = *(int **)(in_ECX + 0x5eac);
      uVar3 = *(int *)(in_ECX + 0x5eb0) - (int)param_1 >> 2;
      uVar6 = 0;
      if (uVar3 != 0) {
        do {
          if (*(uint *)(*param_1 + 8) == *puVar5) {
            puVar4 = *(uint **)(*(int *)(in_ECX + 0x5eac) + uVar6 * 4);
            if (puVar4 != (uint *)0x0) {
              *puVar4 = (uint)(*(char *)((int)puVar5 + 9) != '\n');
              *(char *)(puVar4 + 3) = (char)puVar5[1];
              *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)((int)puVar5 + 5);
              *(undefined2 *)(puVar4 + 4) = *(undefined2 *)((int)puVar5 + 7);
              *(undefined1 *)((int)puVar4 + 0x12) = *(undefined1 *)((int)puVar5 + 9);
              *(undefined2 *)(puVar4 + 5) = *(undefined2 *)((int)puVar5 + 10);
              *(char *)((int)puVar4 + 0x16) = (char)puVar5[3];
            }
            break;
          }
          param_1 = param_1 + 1;
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar3);
      }
      puVar4 = *(uint **)(in_ECX + 0x5ecc);
      if ((puVar4 == (uint *)0x0) || (puVar4[2] != *puVar5)) {
        param_1 = *(int **)(in_ECX + 0x5ed0);
        uVar3 = *(int *)(in_ECX + 0x5ed4) - (int)param_1 >> 2;
        uVar6 = 0;
        if (uVar3 != 0) {
          do {
            if (*(uint *)(*param_1 + 8) == *puVar5) {
              puVar4 = *(uint **)(*(int *)(in_ECX + 0x5ed0) + uVar6 * 4);
              goto LAB_004f18a3;
            }
            param_1 = param_1 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar3);
        }
      }
      else {
LAB_004f18a3:
        if (puVar4 != (uint *)0x0) {
          *puVar4 = (uint)(*(char *)((int)puVar5 + 9) != '\n');
          *(char *)(puVar4 + 3) = (char)puVar5[1];
          *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)((int)puVar5 + 5);
          *(undefined2 *)(puVar4 + 4) = *(undefined2 *)((int)puVar5 + 7);
          *(undefined1 *)((int)puVar4 + 0x12) = *(undefined1 *)((int)puVar5 + 9);
          *(undefined2 *)(puVar4 + 5) = *(undefined2 *)((int)puVar5 + 10);
          *(char *)((int)puVar4 + 0x16) = (char)puVar5[3];
        }
      }
      puVar5 = (uint *)((int)puVar5 + 0xd);
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  FUN_008613c0(*(int *)(in_ECX + 0x5eac),*(int *)(in_ECX + 0x5eb0),
               *(int *)(in_ECX + 0x5eb0) - *(int *)(in_ECX + 0x5eac) >> 2,FUN_004f1020,uVar2);
  FUN_008613c0(*(int *)(in_ECX + 0x5ed0),*(int *)(in_ECX + 0x5ed4),
               *(int *)(in_ECX + 0x5ed4) - *(int *)(in_ECX + 0x5ed0) >> 2,FUN_004f1020);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf424b);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4252);
  ExceptionList = local_10;
  return 0;
}

