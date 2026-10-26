
void FUN_0070d680(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  char *local_c;
  
  cVar1 = *param_4;
  if ((cVar1 == '@') || (cVar1 == '=')) {
    local_c = param_4 + 1;
  }
  else {
    local_c = param_4;
    if (cVar1 == '\x1b') {
      local_c = "binary string";
    }
  }
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  FUN_0070d5f0();
  uVar2 = FUN_006fec70(param_1,&DAT_00c43e90,2);
  FUN_0070d3a0(&local_18,uVar2);
  return;
}

