
void FUN_008b8460(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
                    /* WARNING: Subroutine does not return */
  FID_conflict____longjmp_internal((int *)(param_1 + 0x10),1);
}

