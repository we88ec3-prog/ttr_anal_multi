
undefined4 FUN_00765450(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_ECX;
  undefined8 uVar4;
  
  cVar3 = FUN_00754c20(param_1);
  if (cVar3 == '\0') {
    return 0;
  }
  *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x100000;
  puVar1 = *(undefined4 **)(in_ECX + 100);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    uVar4 = FUN_007461a0(1);
    puVar2 = (undefined4 *)*(undefined4 *)((ulonglong)uVar4 >> 0x20);
  }
  return 1;
}

