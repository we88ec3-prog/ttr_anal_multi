
void FUN_00856ac0(int param_1)

{
  undefined4 ***pppuVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 **ppuStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  int iStack_88;
  void *pvStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  int iStack_50;
  uint uStack_4c;
  undefined1 auStack_40 [36];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091e788;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_40;
  uStack_4c = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  iStack_50 = param_1;
  uStack_54 = 0x856b01;
  FUN_00780260();
  uStack_5c = *(undefined4 *)(param_1 + 0x84);
  iStack_50 = 0;
  uStack_54 = 4;
  iStack_58 = in_ECX + 0x54;
  uStack_60 = 0x856b15;
  FUN_006ddcc0();
  uStack_6c = *(undefined4 *)(param_1 + 0x84);
  uStack_60 = 0;
  uStack_64 = 4;
  iStack_68 = in_ECX + 0x58;
  uStack_70 = 0x856b29;
  FUN_006ddcc0();
  uStack_7c = *(undefined4 *)(param_1 + 0x84);
  uStack_70 = 0;
  uStack_74 = 4;
  iStack_78 = in_ECX + 0x5c;
  uStack_80 = 0x856b3d;
  FUN_006ddcc0();
  uStack_8c = *(uint *)(param_1 + 0x84);
  uStack_80 = 0;
  pvStack_84 = (void *)0x4;
  iStack_88 = in_ECX + 0x60;
  uStack_90 = 0x856b51;
  FUN_006ddcc0();
  uStack_9c = *(undefined4 *)(param_1 + 0x84);
  uStack_90 = 0;
  uStack_94 = 4;
  iStack_98 = in_ECX + 100;
  uStack_a0 = 0x856b65;
  FUN_006ddcc0();
  uStack_ac = *(undefined4 *)(param_1 + 0x84);
  uStack_a0 = 0;
  uStack_a4 = 4;
  ppuStack_a8 = (undefined4 **)(in_ECX + 0x68);
  uStack_b0 = 0x856b79;
  FUN_006ddcc0();
  uStack_b0 = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x6c,4);
  uStack_94 = 0xf;
  iStack_98 = 0;
  ppuStack_a8 = (undefined4 **)((uint)ppuStack_a8 & 0xffffff00);
  uStack_7c = 0;
  FUN_00781ea0();
  if (iStack_98 != 0) {
    pppuVar1 = (undefined4 ***)ppuStack_a8;
    if (uStack_94 < 0x10) {
      pppuVar1 = &ppuStack_a8;
    }
    puVar2 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x90) + 0x54))(&uStack_ac,pppuVar1);
    *(undefined4 *)(in_ECX + 0xb8) = *puVar2;
  }
  if (0xf < uStack_94) {
    FUN_0089120c(ppuStack_a8);
  }
  ExceptionList = pvStack_84;
  __security_check_cookie(uStack_8c ^ (uint)&uStack_b0);
  return;
}

