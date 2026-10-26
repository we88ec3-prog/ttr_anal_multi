
undefined4 * FUN_007f6e10(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int in_ECX;
  char *pcVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c511;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x28,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8._1_3_ = 0;
  puVar5 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    pcVar6 = (char *)(in_ECX + 4);
    if ((DAT_00fe324c & 1) == 0) {
      DAT_00fe324c = DAT_00fe324c | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_007cdeb0();
      _atexit((_func_4879 *)&LAB_00bd09b0);
    }
    local_8._0_1_ = 0;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      pcVar6 = *(char **)pcVar6;
    }
    uVar3 = FUN_007cf850();
    puVar2[1] = 0;
    local_8 = CONCAT31(local_8._1_3_,2);
    *puVar2 = IS3D::CFieldObjectInstanceParticle::vftable;
    puVar2[6] = 0;
    puVar2[7] = 0xf;
    *(undefined1 *)(puVar2 + 2) = 0;
    pcVar4 = pcVar6;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
    puVar2[9] = uVar3;
    puVar5 = puVar2;
  }
  ExceptionList = local_10;
  return puVar5;
}

