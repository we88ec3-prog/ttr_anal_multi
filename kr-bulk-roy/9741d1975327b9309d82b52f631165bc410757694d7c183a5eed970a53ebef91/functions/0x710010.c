
void FUN_00710010(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x30);
  puVar3 = *(undefined4 **)(iVar2 + 0x14);
  bVar4 = 0;
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    if (*(char *)((int)puVar3 + 10) != '\0') break;
    pbVar1 = (byte *)((int)puVar3 + 9);
    puVar3 = (undefined4 *)*puVar3;
    bVar4 = bVar4 | *pbVar1;
  }
  if (bVar4 != 0) {
    FUN_00713370((uint)*(byte *)(puVar3 + 2) << 6 | 0x23,*(undefined4 *)(*(int *)(iVar2 + 0xc) + 8))
    ;
  }
  *(undefined4 *)(iVar2 + 0x20) = 0xffffffff;
  FUN_00713370(0x7fff8016,*(undefined4 *)(*(int *)(iVar2 + 0xc) + 8));
  FUN_00711fe0();
  FUN_00711fe0();
  return;
}

