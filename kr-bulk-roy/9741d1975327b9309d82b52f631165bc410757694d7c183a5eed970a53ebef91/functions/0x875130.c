
undefined4 FUN_00875130(int param_1)

{
  int in_ECX;
  int aiStack_2c [3];
  
  aiStack_2c[2] = 0x875145;
  FUN_008753b0();
  aiStack_2c[2] = 0x875150;
  FUN_00781ea0();
  aiStack_2c[2] = 0;
  aiStack_2c[1] = 4;
  aiStack_2c[0] = in_ECX + 0x2c;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84));
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x28,4,0);
  aiStack_2c[0] = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),aiStack_2c,4,0);
  FUN_00785060(param_1);
  FUN_00785060(param_1);
  FUN_00785060(param_1);
  FUN_00785120(param_1);
  FUN_00785120(param_1);
  FUN_00785120(param_1);
  FUN_00785120(param_1);
  return 1;
}

