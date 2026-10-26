
void FUN_006fd730(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_00700880();
  iVar1 = *(int *)(in_EAX + 0x10);
  *puVar2 = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 **)(iVar1 + 0x1c) = puVar2;
  *(byte *)((int)puVar2 + 5) = *(byte *)(iVar1 + 0x14) & 3;
  *(undefined1 *)(puVar2 + 1) = 6;
  *(undefined1 *)((int)puVar2 + 6) = 0;
  puVar2[3] = param_2;
  *(char *)((int)puVar2 + 7) = (char)param_1;
  if (param_1 != 0) {
    puVar2 = puVar2 + param_1 + 5;
    do {
      puVar2 = puVar2 + -1;
      param_1 = param_1 + -1;
      *puVar2 = 0;
    } while (param_1 != 0);
  }
  return;
}

