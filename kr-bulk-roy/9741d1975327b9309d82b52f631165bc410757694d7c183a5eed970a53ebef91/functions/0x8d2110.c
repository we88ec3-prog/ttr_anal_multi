
int FUN_008d2110(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int in_EAX;
  int in_ECX;
  int in_EDX;
  int iVar8;
  int local_14;
  int local_8;
  
  if (((*(char *)(in_EDX + 0x5d8) != '\0') || (*(char *)(in_EDX + 0x46) != '\0')) ||
     ((iVar8 = in_EAX + *(int *)(in_EDX + 0x20), *(int *)(in_EDX + 0x54c) == 0 &&
      (*(int *)(*(int *)(*(int *)(in_EDX + 4) + 0x80) + 0x30) == 0)))) {
    return 0xa0;
  }
  if (*(int *)(*(int *)(*(int *)(in_EDX + 4) + 0x80) + 0x30) == 0) {
    in_ECX = FUN_008d0c60();
    local_8 = FUN_008d0c60();
  }
  else {
    local_8 = param_3;
  }
  if ((-1 < in_ECX) && (-1 < local_8)) {
    if (*(char *)(in_EDX + 0x45) == '\0') {
      FUN_008b8350(*(undefined4 *)(in_EDX + 0xc));
      *(undefined1 *)(in_EDX + 0x5d8) = 1;
      local_14 = FUN_008d0d00();
      *(undefined1 *)(in_EDX + 0x5d8) = 0;
      if (local_14 == 0) {
        uVar4 = *(undefined4 *)(in_EDX + 0x24);
        uVar5 = *(undefined4 *)(in_EDX + 0x2c);
        uVar6 = *(undefined4 *)(in_EDX + 0x20);
        uVar7 = *(undefined4 *)(in_EDX + 0x28);
        *(undefined4 *)(in_EDX + 0x20) = 0;
        *(undefined4 *)(in_EDX + 0x24) = 0;
        *(undefined4 *)(in_EDX + 0x1c) = param_2;
        *(int *)(in_EDX + 0x18) = iVar8 - param_1;
        *(undefined1 *)(in_EDX + 0x5d8) = 1;
        local_14 = FUN_008d0d00();
        *(undefined1 *)(in_EDX + 0x5d8) = 0;
        if (local_14 == 0) {
          *(undefined4 *)(in_EDX + 0x24) = uVar4;
          *(undefined4 *)(in_EDX + 0x20) = uVar6;
          *(undefined4 *)(in_EDX + 0x28) = uVar7;
          *(undefined4 *)(in_EDX + 0x2c) = uVar5;
          *(undefined4 *)(in_EDX + 0x18) = 0;
          *(undefined4 *)(in_EDX + 0x1c) = 0;
        }
      }
    }
    else {
      iVar1 = *(int *)(in_EDX + 8);
      iVar2 = **(int **)(iVar1 + 0x9c);
      local_14 = FUN_008bcb10(iVar2,2);
      if (local_14 == 0) {
        piVar3 = *(int **)(iVar2 + 0x58);
        *piVar3 = in_ECX;
        piVar3[2] = 0;
        piVar3[3] = 0;
        *(undefined2 *)(piVar3 + 1) = 0x202;
        piVar3[8] = local_8;
        *(undefined2 *)(piVar3 + 9) = 2;
        iVar8 = FUN_008b7c80(iVar8 - param_1);
        piVar3[10] = iVar8 >> 0x10;
        iVar8 = FUN_008b7c80(param_2);
        piVar3[0xb] = iVar8 >> 0x10;
        *(undefined4 *)(iVar1 + 0x80) = 2;
        *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(iVar2 + 0x34);
        *(undefined4 *)(iVar1 + 0x48) = 0x636f6d70;
        *(undefined4 *)(iVar2 + 0x54) = 2;
        return 0;
      }
    }
    return local_14;
  }
  return 0xa0;
}

