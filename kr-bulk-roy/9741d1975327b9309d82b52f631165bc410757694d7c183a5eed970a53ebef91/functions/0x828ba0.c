
void FUN_00828ba0(int *param_1,int *param_2)

{
  int *unaff_EDI;
  undefined1 local_8 [4];
  
  if ((param_1 == (int *)*DAT_00fd93fc) && (param_2 == DAT_00fd93fc)) {
    FUN_00828fa0();
    *unaff_EDI = *DAT_00fd93fc;
    return;
  }
  while (param_1 != param_2) {
    FUN_004a62d0();
    FUN_00828c90(local_8,param_1);
  }
  *unaff_EDI = (int)param_1;
  return;
}

