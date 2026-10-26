
void FUN_004fad20(int *param_1,int *param_2)

{
  int *unaff_EDI;
  undefined1 local_8 [4];
  
  if ((param_1 == (int *)*DAT_00fe1904) && (param_2 == DAT_00fe1904)) {
    FUN_004fb130();
    *unaff_EDI = *DAT_00fe1904;
    return;
  }
  while (param_1 != param_2) {
    FUN_004fb2c0();
    FUN_004fae10(local_8,param_1);
  }
  *unaff_EDI = (int)param_1;
  return;
}

