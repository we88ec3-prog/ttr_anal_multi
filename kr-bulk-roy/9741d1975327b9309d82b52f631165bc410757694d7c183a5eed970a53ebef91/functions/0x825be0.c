
undefined4 * FUN_00825be0(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  puVar2 = param_2;
  puVar4 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar5 = true;
  cVar1 = *(char *)((int)puVar4 + 0x25);
  param_2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar5 = *(byte *)(in_EAX + 0xc) < *(byte *)(puVar4 + 3);
    if (bVar5) {
      puVar3 = (undefined4 *)*puVar4;
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
    }
    param_2 = puVar4;
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x25);
  }
  if (bVar5) {
    if (param_2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar5 = true;
      goto LAB_00825c33;
    }
    FUN_007b5340();
  }
  if (*(byte *)(in_EAX + 0xc) <= *(byte *)(param_2 + 3)) {
    if (*(int *)(in_EAX + 0x14) != 0) {
      FUN_0089120c(*(int *)(in_EAX + 0x14));
    }
    *(undefined4 *)(in_EAX + 0x14) = 0;
    *(undefined4 *)(in_EAX + 0x18) = 0;
    *(undefined4 *)(in_EAX + 0x1c) = 0;
    FUN_0089120c();
    *puVar2 = param_2;
    *(undefined1 *)(puVar2 + 1) = 0;
    return puVar2;
  }
LAB_00825c33:
  puVar4 = (undefined4 *)FUN_0047ebf0(&param_1,bVar5,in_EAX);
  *puVar2 = *puVar4;
  *(undefined1 *)(puVar2 + 1) = 1;
  return puVar2;
}

