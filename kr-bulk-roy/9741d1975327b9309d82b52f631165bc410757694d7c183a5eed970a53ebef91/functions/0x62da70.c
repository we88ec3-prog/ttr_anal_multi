
void FUN_0062da70(void *param_1)

{
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  FID_conflict__memcpy
            (param_1,(void *)((int)param_1 + 4),
             (*(int *)(unaff_ESI + 4) - ((int)param_1 + 4) >> 2) * 4);
  *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + -4;
  *unaff_EDI = param_1;
  return;
}

