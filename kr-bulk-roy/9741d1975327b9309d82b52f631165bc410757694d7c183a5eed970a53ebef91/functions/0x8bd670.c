
void FUN_008bd670(undefined4 param_1,byte *param_2)

{
  char cVar1;
  
  cVar1 = FUN_008bd430(param_1);
  if (cVar1 == '\x02') {
    cVar1 = FUN_008bd330(0,param_1);
  }
  if (((cVar1 == '\x02') || (cVar1 == 'U')) && ((*param_2 & 4) != 0)) {
    FUN_008bd520();
  }
  return;
}

