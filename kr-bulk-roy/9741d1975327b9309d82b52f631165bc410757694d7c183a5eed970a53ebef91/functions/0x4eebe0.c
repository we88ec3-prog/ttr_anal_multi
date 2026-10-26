
int FUN_004eebe0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *in_EDX;
  undefined4 *puVar3;
  byte local_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  
  puVar3 = *(undefined4 **)(in_EAX + 4);
  if (*(char *)((int)puVar3[1] + 0x13) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *in_EDX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x13) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_EAX + 4)) && (*(byte *)(puVar3 + 3) <= *in_EDX)) {
    return (int)puVar3 + 0xe;
  }
  local_c = *in_EDX;
  FUN_00518f20();
  FUN_004eee20(&local_c,puVar3);
  return CONCAT22(uStack_a,CONCAT11(uStack_b,local_c)) + 0xe;
}

