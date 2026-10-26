
undefined4 FUN_007f3210(uint param_1,uint param_2,int param_3,void *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (*(int *)(in_EAX + 4) == 0) {
    return 0x80004005;
  }
  if (*(int *)(in_EAX + 8) == 0) {
    return 0x80004005;
  }
  uVar6 = *(uint *)(in_EAX + 0x28);
  if ((uVar6 < *(int *)(in_EAX + 0x18) + param_1) ||
     (uVar5 = *(uint *)(in_EAX + 0x30), uVar5 < *(int *)(in_EAX + 0x20) + param_2)) {
    FUN_007f33a0();
    if ((*(uint *)(in_EAX + 0x14) <= *(uint *)(in_EAX + 0x24)) ||
       (*(uint *)(in_EAX + 0x1c) <= *(uint *)(in_EAX + 0x2c))) {
      *(undefined4 *)(in_EAX + 0x2c) = 0;
      *(undefined4 *)(in_EAX + 0x24) = 0;
    }
    iVar4 = (**(code **)(**(int **)(in_EAX + 4) + 0x2c))
                      (*(int **)(in_EAX + 4),*(int *)(in_EAX + 0x10) * *(int *)(in_EAX + 0x24),
                       *(int *)(in_EAX + 0x28) * *(int *)(in_EAX + 0x10),in_EAX + 0x34,
                       (-(uint)(*(int *)(in_EAX + 0x24) != 0) & 0xfffff000) + 0x2000);
    if (iVar4 < 0) {
      return 0x80004005;
    }
    if (*(int *)(in_EAX + 0x34) == 0) {
      return 0x80004005;
    }
    iVar4 = (**(code **)(**(int **)(in_EAX + 8) + 0x2c))
                      (*(int **)(in_EAX + 8),*(int *)(in_EAX + 0x2c) * 2,*(int *)(in_EAX + 0x30) * 2
                       ,(int *)(in_EAX + 0x38),
                       (-(uint)(*(int *)(in_EAX + 0x2c) != 0) & 0xfffff000) + 0x2000);
    if (iVar4 < 0) {
      return 0x80004005;
    }
    if (*(int *)(in_EAX + 0x38) == 0) {
      return 0x80004005;
    }
    uVar6 = *(uint *)(in_EAX + 0x28);
    uVar5 = *(uint *)(in_EAX + 0x30);
    *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + uVar6;
    *(int *)(in_EAX + 0x2c) = *(int *)(in_EAX + 0x2c) + uVar5;
  }
  if ((*(int *)(in_EAX + 4) != 0) && (*(int *)(in_EAX + 8) != 0)) {
    if ((param_1 <= uVar6) && (param_2 <= uVar5)) {
      FID_conflict__memcpy
                ((void *)(*(int *)(in_EAX + 0x18) * *(int *)(in_EAX + 0x10) +
                         *(int *)(in_EAX + 0x34)),param_4,*(int *)(in_EAX + 0x10) * param_1);
      uVar1 = *(undefined4 *)(in_EAX + 0x24);
      uVar2 = *(undefined4 *)(in_EAX + 0x28);
      uVar3 = *(undefined4 *)(in_EAX + 0x18);
      if ((param_3 != 0) && (uVar6 = 0, param_2 != 0)) {
        do {
          *(short *)(*(int *)(in_EAX + 0x38) + *(int *)(in_EAX + 0x20) * 2) =
               *(short *)(param_3 + uVar6 * 2) + ((short)uVar1 - (short)uVar2) + (short)uVar3;
          *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + 1;
          uVar6 = uVar6 + 1;
        } while (uVar6 < param_2);
      }
      *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + param_1;
      return 0;
    }
    MessageBoxA((HWND)0x0,"StaticMesh Overflow!","CRITICAL ERROR",0);
  }
  return 0x80004005;
}

