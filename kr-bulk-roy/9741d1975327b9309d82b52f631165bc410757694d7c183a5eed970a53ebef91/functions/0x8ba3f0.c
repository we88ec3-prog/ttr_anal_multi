
void FUN_008ba3f0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  puVar1 = *(undefined4 **)(*(int *)(unaff_ESI + 4) + 0x60);
  uVar2 = puVar1[2];
  if (*(code **)(puVar1[3] + 0x44) != (code *)0x0) {
    (**(code **)(puVar1[3] + 0x44))();
  }
  FUN_008ba300();
  if (*(undefined4 **)(unaff_ESI + 0x9c) != (undefined4 *)0x0) {
    if ((*(uint *)*puVar1 & 0x200) == 0) {
      FUN_008ba2a0(**(undefined4 **)(unaff_ESI + 0x9c));
      **(undefined4 **)(unaff_ESI + 0x9c) = 0;
    }
    FUN_008b9f80(uVar2,*(undefined4 *)(unaff_ESI + 0x9c));
    *(undefined4 *)(unaff_ESI + 0x9c) = 0;
  }
  return;
}

