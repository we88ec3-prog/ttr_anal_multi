
void FUN_0055fc50(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *unaff_ESI;
  longlong local_20;
  int local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*unaff_ESI != 0) {
    local_14 = (unaff_ESI[0xd] + -0x300) / 2;
    iVar2 = (unaff_ESI[0xc] + -0x400) / 2;
    if (unaff_ESI[2] != 0) {
      local_20 = 0x3f8000003fa60000;
      (**(code **)(*(int *)unaff_ESI[2] + 0x24))
                (iVar2 + 0xda,local_14 + 0x6d,0,&local_20,0,0,0xffffffff);
    }
    FUN_0056ca70();
    if ((unaff_ESI[0xb] == 2) && ((float)unaff_ESI[0x16] == 1.0)) {
      puVar1 = (undefined4 *)FUN_0055ee20();
      uStack_10 = 0x42000000;
      uStack_c = 0x41c00000;
      local_20 = (longlong)ROUND((float)unaff_ESI[0x1a] * 255.0);
      (**(code **)(*(int *)*puVar1 + 0x24))
                (iVar2,local_14,0,&uStack_10,0,0,(int)local_20 << 0x18 | 0xffffff);
    }
  }
  return;
}

