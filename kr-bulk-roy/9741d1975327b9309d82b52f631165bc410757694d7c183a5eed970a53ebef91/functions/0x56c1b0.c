
undefined4 * FUN_0056c1b0(int *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *puVar4;
  
  puVar2 = param_1;
  bVar1 = true;
  param_1 = DAT_00fe1dc0;
  if (*(char *)(DAT_00fe1dc0[1] + 0x2d) == '\0') {
    piVar3 = (int *)DAT_00fe1dc0[1];
    do {
      param_1 = piVar3;
      bVar1 = *(int *)(in_EAX + 0xc) < param_1[3];
      if (bVar1) {
        piVar3 = (int *)*param_1;
      }
      else {
        piVar3 = (int *)param_1[2];
      }
    } while (*(char *)((int)piVar3 + 0x2d) == '\0');
  }
  if (bVar1) {
    if (param_1 == (int *)*DAT_00fe1dc0) {
      puVar4 = (undefined4 *)FUN_0056c2a0(&param_1,1);
      *puVar2 = *puVar4;
      *(undefined1 *)(puVar2 + 1) = 1;
      return puVar2;
    }
    FUN_00574e80();
  }
  if (*(int *)(in_EAX + 0xc) <= param_1[3]) {
    if (0xf < *(uint *)(in_EAX + 0x24)) {
      FUN_0089120c(*(undefined4 *)(in_EAX + 0x10));
    }
    *(undefined4 *)(in_EAX + 0x24) = 0xf;
    *(undefined4 *)(in_EAX + 0x20) = 0;
    *(undefined1 *)(in_EAX + 0x10) = 0;
    FUN_0089120c();
    *puVar2 = param_1;
    *(undefined1 *)(puVar2 + 1) = 0;
    return puVar2;
  }
  puVar4 = (undefined4 *)FUN_0056c2a0(&param_1,bVar1);
  *puVar2 = *puVar4;
  *(undefined1 *)(puVar2 + 1) = 1;
  return puVar2;
}

