
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_006d1da0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092284d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fdf3f0;
  _DAT_00fdf3f0 = 0;
  _eh_vector_constructor_iterator_(&DAT_00fdf3f4,0x10,3,FUN_006d2c40,FUN_006d2cb0);
  local_8 = 0;
  _DAT_00fdf628 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fdf624 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf624 + 4) = DAT_00fdf624;
  local_8._0_1_ = 1;
  _DAT_00fdf638 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fdf634 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf634 + 4) = DAT_00fdf634;
  *(int *)(DAT_00fdf634 + 8) = DAT_00fdf634;
  *(undefined1 *)(DAT_00fdf634 + 0x14) = 1;
  *(undefined1 *)(DAT_00fdf634 + 0x15) = 1;
  local_8._0_1_ = 2;
  _DAT_00fdf648 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fdf644 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf644 + 4) = DAT_00fdf644;
  *(int *)(DAT_00fdf644 + 8) = DAT_00fdf644;
  *(undefined1 *)(DAT_00fdf644 + 0x14) = 1;
  *(undefined1 *)(DAT_00fdf644 + 0x15) = 1;
  local_8._0_1_ = 3;
  _DAT_00fdf658 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fdf654 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fdf654 + 4) = DAT_00fdf654;
  *(int *)(DAT_00fdf654 + 8) = DAT_00fdf654;
  *(undefined1 *)(DAT_00fdf654 + 0x14) = 1;
  *(undefined1 *)(DAT_00fdf654 + 0x15) = 1;
  _DAT_00fdf660 = 0;
  _DAT_00fdf664 = 0;
  DAT_00fdf668 = 0;
  DAT_00fdf66c = 0;
  _DAT_00fdf670 = 0;
  _DAT_00fdf674 = 0;
  local_8._0_1_ = 5;
  FUN_006d2e70();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 6;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 5;
  }
  if (DAT_00fb91e9 == '\x02') {
    FUN_006d3960();
  }
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2774;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2775;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2776;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x283c;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x283d;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x283e;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x283f;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2840;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2841;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2842;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2843;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2844;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2845;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2846;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2847;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2848;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2849;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x284a;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x284b;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x284c;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x284d;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a0;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a1;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a2;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a3;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a4;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a5;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x28a6;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2904;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2905;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2906;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2907;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2908;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2909;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x290a;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x290c;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x290e;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x290f;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2913;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2914;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2915;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2916;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2917;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2918;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x2919;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  iVar2 = DAT_00fdf624;
  local_14 = (char *)0x291a;
  iVar3 = FUN_0074d700(DAT_00fdf624,*(undefined4 *)(DAT_00fdf624 + 4),&local_14);
  if (_DAT_00fdf628 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  _DAT_00fdf628 = _DAT_00fdf628 + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  local_14 = (char *)0x2af8;
  FUN_0074a200();
  local_14 = (char *)0x2af9;
  FUN_0074a200();
  local_14 = (char *)0x2afa;
  FUN_0074a200();
  local_14 = (char *)0x2afb;
  FUN_0074a200();
  FUN_006d4260(2);
  FUN_00823850();
  FUN_00823850();
  FUN_00823850();
  ExceptionList = local_10;
  return &DAT_00fdf3f0;
}

