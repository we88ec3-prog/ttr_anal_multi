
/* WARNING: Removing unreachable block (ram,0x00786f08) */
/* WARNING: Removing unreachable block (ram,0x00786f1d) */

undefined4 FUN_00786ec0(int param_1)

{
  int in_ECX;
  undefined4 uStack_1c;
  
  uStack_1c = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 8,0xc);
  uStack_1c = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_1c,4);
  return 1;
}

