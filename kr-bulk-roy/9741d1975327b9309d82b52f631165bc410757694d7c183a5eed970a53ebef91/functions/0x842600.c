
void FUN_00842600(float *param_1,float param_2,float param_3,float param_4)

{
  float *unaff_ESI;
  float *unaff_EDI;
  
  if (unaff_ESI[2] * param_4 + *unaff_ESI * param_2 + unaff_ESI[1] * param_3 <
      param_4 * unaff_EDI[2] + param_3 * unaff_EDI[1] + param_2 * *unaff_EDI) {
    FUN_00842710();
  }
  if (param_1[2] * param_4 + *param_1 * param_2 + param_1[1] * param_3 <
      unaff_ESI[2] * param_4 + *unaff_ESI * param_2 + unaff_ESI[1] * param_3) {
    FUN_00842710(param_1);
  }
  if (unaff_ESI[1] * param_3 + *unaff_ESI * param_2 + unaff_ESI[2] * param_4 <
      param_4 * unaff_EDI[2] + param_3 * unaff_EDI[1] + *unaff_EDI * param_2) {
    FUN_00842710();
  }
  return;
}

