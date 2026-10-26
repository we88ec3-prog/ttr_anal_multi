
undefined4 * FUN_00536bc0(int *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *puVar4;
  
  puVar2 = param_1;
  bVar1 = true;
  param_1 = DAT_00fe36f4;
  if (*(char *)(DAT_00fe36f4[1] + 0x31) == '\0') {
    piVar3 = (int *)DAT_00fe36f4[1];
    do {
      param_1 = piVar3;
      bVar1 = *(int *)(in_EAX + 0xc) < param_1[3];
      if (bVar1) {
        piVar3 = (int *)*param_1;
      }
      else {
        piVar3 = (int *)param_1[2];
      }
    } while (*(char *)((int)piVar3 + 0x31) == '\0');
  }
  if (bVar1) {
    if (param_1 == (int *)*DAT_00fe36f4) {
      puVar4 = (undefined4 *)FUN_00536cb0(&param_1,1);
      *puVar2 = *puVar4;
      *(undefined1 *)(puVar2 + 1) = 1;
      return puVar2;
    }
    FUN_00536ea0();
  }
  if (*(int *)(in_EAX + 0xc) <= param_1[3]) {
    if (7 < *(uint *)(in_EAX + 0x24)) {
      FUN_0089120c(*(undefined4 *)(in_EAX + 0x10));
    }
    *(undefined4 *)(in_EAX + 0x24) = 7;
    *(undefined4 *)(in_EAX + 0x20) = 0;
    *(undefined2 *)(in_EAX + 0x10) = 0;
    FUN_0089120c();
    *puVar2 = param_1;
    *(undefined1 *)(puVar2 + 1) = 0;
    return puVar2;
  }
  puVar4 = (undefined4 *)FUN_00536cb0(&param_1,bVar1);
  *puVar2 = *puVar4;
  *(undefined1 *)(puVar2 + 1) = 1;
  return puVar2;
}

