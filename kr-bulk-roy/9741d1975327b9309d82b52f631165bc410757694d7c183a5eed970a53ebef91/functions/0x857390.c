
/* WARNING: Removing unreachable block (ram,0x0085747d) */
/* WARNING: Switch with 1 destination removed at 0x00857440 : 2 cases all go to same destination */

undefined4 FUN_00857390(undefined4 param_1,int param_2)

{
  uint unaff_EDI;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 *puStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uVar1;
  undefined1 auStack_44 [4];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_60 = *(undefined4 *)(param_2 + 0x84);
  uStack_54 = 0;
  uStack_58 = 4;
  puStack_5c = &local_40;
  local_40 = 0;
  uStack_64 = 0x8573b9;
  FUN_006ddcc0();
  if (unaff_EDI == 0) {
    return 0;
  }
  uVar1 = 0;
  if (unaff_EDI != 0) {
    do {
      uStack_64 = 0;
      uStack_3c = 0x11;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),&stack0xffffffb8,4);
      FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),&stack0xffffffb4,4);
      FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),&uStack_58,4,0);
      FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),&uStack_64,4,0);
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      uStack_30 = FUN_0087dc3d(0);
      uStack_28 = uStack_3c;
      uStack_24 = uStack_38;
      uStack_20 = uStack_34;
      uStack_64 = 0x8574c2;
      uStack_1c = uStack_30;
      uStack_64 = FUN_0054f7d0();
      FUN_008575f0(auStack_44);
      uVar1 = uVar1 + 1;
    } while (uVar1 < unaff_EDI);
  }
  return 1;
}

