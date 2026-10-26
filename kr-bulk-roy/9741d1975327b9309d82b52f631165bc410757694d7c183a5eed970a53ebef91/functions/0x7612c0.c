
void FUN_007612c0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined1 *puVar2;
  int iVar3;
  
  if (*(char *)(in_EAX + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(in_EAX + 0x168) = 0;
  *(undefined4 *)(in_EAX + 0x160) = 0;
  *(undefined4 *)(in_EAX + 0x164) = 0;
  *(undefined4 *)(in_EAX + 0x14c) = 0;
  FUN_007578f0();
  puVar1 = *(undefined4 **)(in_EAX + 0x148);
  puVar2 = (undefined1 *)*puVar1;
  if (puVar2 != (undefined1 *)0x0) {
    for (iVar3 = puVar1[1] * 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    FUN_00891d3d(*puVar1);
    *puVar1 = 0;
    puVar1[2] = 0;
  }
  return;
}

