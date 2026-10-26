
void FUN_00709d90(int param_1)

{
  undefined4 *puVar1;
  int _Code;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar1[2])) {
    _Code = FUN_006f6370(param_1,1);
  }
  else {
    _Code = 0;
  }
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}

