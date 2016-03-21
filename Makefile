.PHONY: clean All

All:
	@echo "----------Building project:[ Assignment08 - Debug ]----------"
	@cd "Assignment08" && "$(MAKE)" -f  "Assignment08.mk"
clean:
	@echo "----------Cleaning project:[ Assignment08 - Debug ]----------"
	@cd "Assignment08" && "$(MAKE)" -f  "Assignment08.mk" clean
