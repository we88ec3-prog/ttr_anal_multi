
void FUN_006fdb40(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x70) + 0x44) = param_2;
                    /* WARNING: Subroutine does not return */
    FID_conflict____longjmp_internal((int *)(*(int *)(param_1 + 0x70) + 4),1);
  }
  *(char *)(param_1 + 6) = (char)param_2;
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x58) != 0) {
    FUN_006fdad0(param_2);
    (**(code **)(*(int *)(param_1 + 0x10) + 0x58))(param_1);
  }
                    /* WARNING: Subroutine does not return */
  _exit(1);
}

