
undefined4 * FUN_00740570(undefined4 param_1)

{
  undefined4 *puVar1;
  void *_Dst;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)FUN_00891268(0x34);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = FTGlyphCache::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(undefined2 *)(puVar1 + 6) = 0;
    *(undefined1 *)((int)puVar1 + 0x1a) = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
  }
  puVar1[1] = param_1;
  puVar1[2] = *(undefined4 *)(unaff_ESI + 0x4c);
  puVar1[3] = *(undefined4 *)(unaff_ESI + 0x50);
  puVar1[4] = *(undefined4 *)(unaff_ESI + 0x54);
  *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(unaff_ESI + 0x5c);
  *(undefined1 *)((int)puVar1 + 0x1a) = *(undefined1 *)(unaff_ESI + 0x5e);
  _Dst = (void *)FUN_0087dc3d(*(int *)(unaff_ESI + 0x4c) * *(int *)(unaff_ESI + 0x54));
  puVar1[5] = _Dst;
  FID_conflict__memcpy
            (_Dst,*(void **)(unaff_ESI + 0x58),
             *(int *)(unaff_ESI + 0x4c) * *(int *)(unaff_ESI + 0x54));
  puVar1[7] = *(undefined4 *)(unaff_ESI + 100);
  puVar1[8] = *(undefined4 *)(unaff_ESI + 0x68);
  puVar1[9] = *(undefined4 *)(unaff_ESI + 0x40);
  puVar1[10] = *(undefined4 *)(unaff_ESI + 0x44);
  return puVar1;
}

