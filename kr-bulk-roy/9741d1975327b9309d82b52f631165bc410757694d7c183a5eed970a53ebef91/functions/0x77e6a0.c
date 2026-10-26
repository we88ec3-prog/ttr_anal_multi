
undefined4 FUN_0077e6a0(int param_1)

{
  int in_ECX;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = param_1;
  uStack_20 = 0x77e6b6;
  FUN_00780260();
  uStack_28 = *(undefined4 *)(param_1 + 0x84);
  iStack_1c = 0;
  uStack_20 = 0x1c;
  iStack_24 = in_ECX + 0x54;
  uStack_2c = 0x77e6ca;
  FUN_006ddcc0();
  uStack_2c = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&iStack_1c,4);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_2c,4,0);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x74,4,0);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x78,4,0);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x7c,4,0);
  return 1;
}

