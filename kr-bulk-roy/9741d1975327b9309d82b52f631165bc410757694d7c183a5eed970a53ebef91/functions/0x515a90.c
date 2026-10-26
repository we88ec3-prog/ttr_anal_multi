
int FUN_00515a90(void)

{
  byte *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  byte local_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  undefined2 uStack_8;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x13) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *in_EAX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x13) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_ECX + 4)) && (*(byte *)(puVar3 + 3) <= *in_EAX)) {
    return (int)puVar3 + 0xe;
  }
  local_c = *in_EAX;
  uStack_a = 0;
  uStack_8 = 0;
  FUN_00518f20();
  FUN_004eee20(&local_c,puVar3);
  return CONCAT22(uStack_a,CONCAT11(uStack_b,local_c)) + 0xe;
}

