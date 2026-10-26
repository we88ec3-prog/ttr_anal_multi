
void FUN_008d0590(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 local_c;
  char *local_8;
  
  pcVar2 = (char *)*param_1;
  pcVar3 = (char *)param_1[2];
  local_c = 0;
  local_8 = pcVar2;
  FUN_008d02f0();
  if (pcVar3 <= local_8) goto LAB_008d06bf;
  cVar1 = *local_8;
  if ((cVar1 == '[') || (cVar1 == ']')) {
LAB_008d06ae:
    local_8 = local_8 + 1;
  }
  else if (cVar1 == '{') {
    local_c = FUN_008d0480(&local_8);
  }
  else if (cVar1 == '(') {
    local_c = FUN_008d0340(&local_8);
  }
  else if (cVar1 == '<') {
    if ((local_8 + 1 < pcVar3) && (local_8[1] == '<')) {
      local_8 = local_8 + 2;
    }
    else {
      local_c = FUN_008d0420();
    }
  }
  else if (cVar1 == '>') {
    local_8 = local_8 + 1;
    if ((local_8 < pcVar3) && (*local_8 == '>')) goto LAB_008d06ae;
    local_c = 3;
  }
  else {
    if (cVar1 == '/') {
      local_8 = local_8 + 1;
    }
    if (pcVar3 <= local_8) goto LAB_008d06bf;
    while ((((((cVar1 = *local_8, cVar1 != ' ' && (cVar1 != '\r')) && (cVar1 != '\n')) &&
             ((cVar1 != '\t' && (cVar1 != '\f')))) &&
            (((cVar1 != '\0' && ((cVar1 != '/' && (cVar1 != '(')))) && (cVar1 != ')')))) &&
           ((((cVar1 != '<' && (cVar1 != '>')) && (cVar1 != '[')) &&
            (((cVar1 != ']' && (cVar1 != '{')) && ((cVar1 != '}' && (cVar1 != '%'))))))))) {
      local_8 = local_8 + 1;
      if (pcVar3 <= local_8) {
        param_1[3] = 0;
        *param_1 = local_8;
        return;
      }
    }
  }
  if ((local_8 < pcVar3) && (local_8 == pcVar2)) {
    local_c = 3;
  }
LAB_008d06bf:
  param_1[3] = local_c;
  *param_1 = local_8;
  return;
}

